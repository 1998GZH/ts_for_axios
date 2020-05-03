import axios from "../../dist/ts-axios.es5"

axios({
  method: 'post',
  url: '/base/post',
  data: {
    a: 1,
    b: 2
  }
})
  .then((res) => {
    console.log(res)
  })
  .catch(err => {
    console.error(err);
  })

axios({
  method: 'post',
  url: '/base/post',
  responseType: 'json',
  data: {
    a: 3,
    b: 4
  }
})
  .then((res) => {
    console.log(res)
  })
  .catch(err => {
    console.error(err);
  })