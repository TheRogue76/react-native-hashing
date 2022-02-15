import * as React from 'react';

import { StyleSheet, View, Text } from 'react-native';
import { sha256 } from 'react-native-hashing';

export default function App() {
  return (
    <View style={styles.container}>
      <Text>Result: {sha256('hello world')}</Text>
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
