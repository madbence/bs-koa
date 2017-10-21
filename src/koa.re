type t;

type error;

type listener = option error => unit;

type ctx;

external make : unit => t = "koa" [@@bs.new] [@@bs.module];

external listen : t => int => listener => unit = "listen" [@@bs.send];

external use : t => (ctx => (unit => Js.Promise.t unit) => Js.Promise.t unit) => t =
  "use" [@@bs.send];

external respond: ctx => string => unit = "body" [@@bs.set];
