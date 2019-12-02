import '../../deps/vue/mock-env.js'
import App from './app.js'
import renderToString from '../../deps/vue/server-renderer.js'

renderToString(App, {}, (err, html) => {
  globalThis.vue_render_res = err || html
})