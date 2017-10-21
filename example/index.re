open Koa;

let app = make ();

let mkHandler name ctx next =>
  Js.Promise.resolve ()
  |> Js.Promise.then_ (
       fun _ => {
         Js.log (name ^ " before");
         Js.Promise.resolve ()
       }
     )
  |> Js.Promise.then_ next
  |> Js.Promise.then_ (
       fun _ => {
         Js.log (name ^ " after");
         respond ctx "Hello world!";
         Js.Promise.resolve ()
       }
     );

use app (mkHandler "outer");

use app (mkHandler "inner");

listen app 1337 (fun _ => ());
