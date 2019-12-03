import Vue from '../deps/vue/vue.js'
import ByWho from './component.js'

export default new Vue({
  components: {
    'by-who': ByWho
  },
  template: '<div>{{test}} by <by-who></by-who></div>',
  data: {
    test: 'hello world'
  }
})