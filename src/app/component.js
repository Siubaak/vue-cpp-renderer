export default {
  template: '<span>{{toUpperCase(name)}}</span>',
  data() {
    return {
      name: 'siubaak'
    }
  },
  methods: {
    toUpperCase(str) {
      return str.toUpperCase()
    }
  }
}