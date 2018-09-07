[@bs.module "react-native-websocket"]
external websocketClass: ReasonReact.reactClass = "default";

[@bs.send] external send: (ReasonReact.reactRef, string) => unit = "";

type event = Js.Dict.t(string);

let make =
    (
      ~url: string,
      ~onOpen: unit => unit,
      ~onMessage: event => unit,
      ~onError: unit => unit,
      ~onClose: unit => unit,
      ~reconnect: option(bool)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=websocketClass,
    ~props={
      "url": url,
      "onOpen": onOpen,
      "onMessage": onMessage,
      "onError": onError,
      "onClose": onClose,
      "reconnect": reconnect,
    },
    children,
  );