const toString = Object.prototype.toString

// val is Date类型保护,确认val有Date的方法
export function isDate(val: any): val is Date {
  return toString.call(val) === '[object Date]'
}

/* export function isObject(val: any): val is Object {
  return val !== null && typeof val === 'object';
} */

// 如果用type进行判断 ArrayBuffer 和 FormData对象也是object无法区分
export function isPlainObject(val: any): val is Object {
  return toString.call(val) === '[object Object]'
}
