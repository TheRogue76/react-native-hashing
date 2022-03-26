<h1 align='center'>React Native Hashing</h1>

<p align="center">
  <a href="https://www.npmjs.com/package/react-native-hashing"><img src="https://img.shields.io/npm/dm/react-native-hashing.svg?style=flat-square" alt="NPM downloads"></a>
  <a href="https://www.npmjs.com/package/react-native-hashing"><img src="https://img.shields.io/npm/v/react-native-hashing.svg?style=flat-square" alt="NPM version"></a>
  <a href="/LICENSE"><img src="https://img.shields.io/npm/l/react-native-hashing.svg?style=flat-square" alt="License"></a>
</p>

[//]: # (**THIS PACKAGE IS UNDER ACTIVE DEVELOPMENT AND YOU SHOULD NOT USE IT IN PRODUCTION. IF SO, USE IT ON YOUR OWN RESPONSIBILITY.**)

A hashing library for react native written in C++ and JSI

## Installation

```sh
npm install react-native-hashing
```

or

```sh
yarn add react-native-hashing
```

## Usage

```js
import { sha256, md5, sha1, sha3 } from "react-native-hashing";

// ...

const result = sha256('Hello world');

or

const result = md5('Hello world');

or

const result = sha1('Hello world');

or

const result = sha3('Hello world');
```

## Acknowledgements

Big thanks to Stephan Brumme for the C++ implementation of the hashing algorithms. [Link to his library](https://github.com/stbrumme/hash-library)

## Contributing

See the [contributing guide](CONTRIBUTING.md) to learn how to contribute to the repository and the development workflow.

## License

MIT
