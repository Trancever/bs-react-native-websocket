# bs-react-native-websocket

### This package provide Reasonml bindings for [react-native-websocket](https://www.npmjs.com/package/react-native-websocket) component.

## Installation

```
$ yarn add bs-react-native-websocket react-native-websocket
```

Then update your `bsconfig.json`, add `bs-react-native-websocket` to bs-dependencies.

```json
"bs-dependencies": ["bs-react-native-websocket"]
```

## Usage

Usage is very similar to react-native-websocket.

Example:

```js
type state = {
  socketRef: ref(option(ReasonReact.reactRef)),
};

let setSocketRef = (theRef, {ReasonReact.state}) =>
  state.socketRef := Js.Nullable.toOption(theRef);

let component = ReasonReact.reducerComponent("Component");

let make =
    (
      _children,
    ) => {
  ...component,
  initialState: () => {socketRef: ref(None)},
  render: self =>
    <View>
      <ReactNativeWebsocket
        url="ws://localhost:5000"
        onOpen={() => Js.log("successfull connection")}
        onMessage={
          event =>
            Js.log(event) // event is a Js.dict object
        }
        onError={() => Js.log("get error")}
        onClose={() => Js.log("connection closed")}
        ref={self.handle(setSocketRef)}
        reconnect=true
      />
    </View>,
};
```

Example of sending data:

```js
// socket is ref to ReactNativeWebsocket component
// data is a stringifiedData that you want to send
ReactNativeWebsocket.send(socketRef, data);
```

## License

MIT

## Contributing

PR's are welcome!
