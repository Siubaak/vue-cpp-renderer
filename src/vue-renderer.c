#include "vue-renderer.h"

const char *render_vue_app(const char *vue_app_file)
{
  JSRuntime *rt;
  JSContext *ctx;
  rt = JS_NewRuntime();
  ctx = JS_NewContextRaw(rt);
  JS_SetModuleLoaderFunc(rt, NULL, js_module_loader, NULL);
  JS_AddIntrinsicBaseObjects(ctx);
  JS_AddIntrinsicDate(ctx);
  JS_AddIntrinsicEval(ctx);
  JS_AddIntrinsicStringNormalize(ctx);
  JS_AddIntrinsicRegExp(ctx);
  JS_AddIntrinsicJSON(ctx);
  JS_AddIntrinsicProxy(ctx);
  JS_AddIntrinsicMapSet(ctx);
  JS_AddIntrinsicTypedArrays(ctx);
  JS_AddIntrinsicPromise(ctx);

  size_t buf_len;
  uint8_t *buf = js_load_file(ctx, &buf_len, vue_app_file);
  JS_Eval(ctx, (char *)buf, buf_len, vue_app_file, JS_EVAL_TYPE_MODULE);

  const char *code = "globalThis.vue_render_res";
  JSValue ret = JS_Eval(ctx, code, strlen(code), "<evalScript>", JS_EVAL_TYPE_GLOBAL);

  const char *vue_render_res = JS_ToCString(ctx, ret);

  js_std_loop(ctx);
  JS_FreeContext(ctx);
  JS_FreeRuntime(rt);

  return vue_render_res;
}