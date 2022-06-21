# react-native-image-blur

  由于 react-native-blur 与 react-native-screens 使用会产生 Recording currently in progress - missing #endRecording() call 错误。
[合并了#1406也还是有问题](https://github.com/software-mansion/react-native-screens/pull/1406)，所以决定制作这个库。
目前只是用于方便自己使用，如有问题欢迎提issues或pull request

  Because react-native-blur and react-native-screens use Recording currently in progress - missing #endRecording() call error.
[I still have problems with merging #1406](https://github.com/software-mansion/react-native-screens/pull/1406), so I decided to make this library.
At present, it is only for your own convenience. If you have any questions, please submit issues or pull requests.

## Getting started

`$ npm install @byron-react-native/image-blur --save`

## Usage
```javascript
import React, {Component} from 'react';
import {Platform, StyleSheet, Text, View} from 'react-native';
import ImageBlur from '@byron-react-native/image-blur';
import {ImageBackground, ActivityIndicator, StatusBar} from 'react-native';
import RNFS from 'react-native-fs';
import MD5 from 'crypto-js/md5';

const url = 'https://kaiguang-assets.ibanquan.com/gxuqtvv6tfd4xik9la0ulrl1k6t8';

export default class App extends Component {
  state = {
    uri: '',
  };

  loadCache = async () => {
    try {
      const existsDir = await RNFS.exists(RNFS.CachesDirectoryPath);
      if (!existsDir) {
        await RNFS.mkdir(RNFS.CachesDirectoryPath);
      }
      const name = MD5(url);
      const toFile = `${RNFS.CachesDirectoryPath}/${name}.png`;
      const existsFile = await RNFS.exists(toFile);
      if (existsFile) {
        console.log(' >> from cache ', toFile);
        this.loadBlur(toFile);
        return;
      }
      const saveFile = RNFS.downloadFile({
        fromUrl: url,
        toFile: toFile,
      });
      const res = await saveFile.promise;
      if (res.statusCode !== 200) {
        this.setState({uri: url});
        return;
      }
      this.loadBlur(toFile);
    } catch (e) {
      console.log(' >> fs err ', e);
      this.setState({uri: url});
    }
  };

  loadBlur = async fromPath => {
    console.log(' >> load blur', fromPath);
    try {
      const name = MD5(url);
      const toFile = `${name}_blur.png`;
      const str = await ImageBlur.blur(fromPath, toFile, 32);
      console.log(' >> blur res ', str);
      this.setState({
        uri: Platform.OS === 'android' ? `file://${str}` : str,
      });
    } catch (e) {
      console.log(' >> blur err ', e);
      this.setState({uri: url});
    }
  };

  componentDidMount() {
    this.loadCache();
  }

  render() {
    if (!this.state.uri) {
      return (
        <View style={styles.container}>
          <ActivityIndicator color={'#000'} />
        </View>
      );
    }
    return (
      <>
        <StatusBar
          translucent={true}
          backgroundColor={'transparent'}
          barStyle={'light-content'}
        />
        <ImageBackground
          style={styles.container}
          source={{uri: this.state.uri}}>
          <Text style={styles.welcome}>☆ImageBlur example☆</Text>
          <Text style={styles.welcome}>☆NATIVE CALLBACK MESSAGE☆</Text>
        </ImageBackground>
      </>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#F5FCFF',
  },
  welcome: {
    fontSize: 20,
    textAlign: 'center',
    margin: 10,
    color: '#fff',
  },
});

```
## Screenshot

<img src="https://github.com/472647301/react-native-image-blur/blob/main/example/screenshot.png?raw=true" width="1038">