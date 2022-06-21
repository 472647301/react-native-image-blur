// ImageBlurModule.java

package com.byronimageblur;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;

import net.qiujuer.genius.blur.StackBlur;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class ImageBlurModule extends ReactContextBaseJavaModule {

    public ImageBlurModule(ReactApplicationContext reactContext) {
        super(reactContext);
    }

    @NonNull
    @Override
    public String getName() {
        return "ImageBlur";
    }

    @ReactMethod
    public void blur(String fromPath, String toFile, int radius, Promise promise) {
        File file = new File(getReactApplicationContext().getCacheDir().getAbsolutePath(), toFile);
        if (file.exists()) {
            promise.resolve(file.getPath());
            return;
        }
        FileInputStream fis = null;
        try {
            fis = new FileInputStream(fromPath);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            promise.reject("404", "404");
        }
        BitmapFactory.Options options = new BitmapFactory.Options();
        Bitmap bitmap = BitmapFactory.decodeStream(fis,null, options);
        Bitmap blurImage = StackBlur.blurNatively(bitmap, radius, true);
        FileOutputStream saveImgOut = null;
        try {
            saveImgOut = new FileOutputStream(file);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            promise.reject("404", "404");
        }
        blurImage.compress(Bitmap.CompressFormat.PNG, 80, saveImgOut);
        if (saveImgOut != null) {
            try {
                saveImgOut.flush();
            } catch (IOException e) {
                e.printStackTrace();
                promise.reject("404", "404");
            }
        }
        if (saveImgOut != null) {
            try {
                saveImgOut.close();
            } catch (IOException e) {
                e.printStackTrace();
                promise.reject("404", "404");
            }
        }
        promise.resolve(file.getPath());
    }
}
