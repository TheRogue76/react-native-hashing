import * as React from 'react';

import { StyleSheet, View, Text } from 'react-native';
import { sha256, md5 } from 'react-native-hashing';

export default function App() {
  return (
    <View style={styles.container}>
      <Text>our text is: hello world</Text>
      <Text>sha256: {sha256('hello world')}</Text>
      <Text>md5: {md5('hello world')}</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
});
