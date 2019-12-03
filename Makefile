libvuerenderer.a: vue-renderer.c deps/quickjs/libquickjs.a
	gcc $^ -shared -o $@

demo: index.c libvuerenderer.a
	gcc $^ -o demo.out
