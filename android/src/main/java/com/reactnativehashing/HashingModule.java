package com.reactnativehashing;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.module.annotations.ReactModule;

@ReactModule(name = HashingModule.NAME)
public class HashingModule extends ReactContextBaseJavaModule {
    static {
        try {
            // Used to load the 'native-lib' library on application startup.
            System.loadLibrary("cpp");
        } catch (Exception ignored) {
        }
    }
    public static final String NAME = "Hashing";

    public static native initialize(long jsiPtr);
    public static native destruct();

    public HashingModule(ReactApplicationContext reactContext) {
        super(reactContext);
    }

    @Override
    @NonNull
    public String getName() {
        return NAME;
    }

    @NonNull
    @Override
    public void initialize() {
      super.initialize();
      HashingModule.initialize(this.getReactApplicationContext().getJavaScriptContextHolder().get());
    }

    @Override
    public void onCatalystInstanceDestroy() {
      HashingModule.destruct();
    }
}
