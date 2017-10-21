type t;
type error;
type ctx;
type listener = option error => unit;
let make: unit => t;
let listen: t => int => listener => unit;
let use: t => (ctx => (unit => Js.Promise.t unit) => Js.Promise.t unit) => t;
let respond: ctx => string => unit;
