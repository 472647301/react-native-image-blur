declare module "@byron-react-native/image-blur" {
  class ImageBlur {
    /**
     *
     * @param fromPath 源图片绝对路径
     * @param toFile 缓存文件名(不带路径)
     * @param radius 模糊值
     */
    static blur(
      fromPath: string,
      toFile: string,
      radius: number
    ): Promise<string>;
  }
  export default ImageBlur;
}
