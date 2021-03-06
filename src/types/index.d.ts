export type Method =
  | 'get'
  | 'GET'
  | 'put'
  | 'PUT'
  | 'post'
  | 'POST'
  | 'head'
  | 'HEAD'
  | 'patch'
  | 'PATCH'
  | 'delete'
  | 'DELETE'
  | 'otions'
  | 'OPTIONS'

export interface AxiosRequestConfig {
  url: string
  method?: Method
  data?: any
  params?: any
  headers?: any
  responseType?: XMLHttpRequestResponseType
  timeout?: number
}

export interface AxiosResponse {
  data: any
  status: any
  statusText: any
  headers: any
  config: AxiosRequestConfig
  request: any
}

export interface AxiosPromise extends Promise<AxiosResponse> {}

export interface AxiosError extends Error {
  code?: string | null
  request?: any
  response?: AxiosResponse
  config: AxiosRequestConfig
  isAxiosError: boolean
}
