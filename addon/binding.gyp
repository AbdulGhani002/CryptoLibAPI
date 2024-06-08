{
  "targets": [
    {
      "target_name": "CryptoLib",
      "sources": ["CryptoLib.cpp", "CryptoLibWrapper.cpp"],
      "include_dirs": ["<!(node -e \"require('node-addon-api').include\")"],
      "dependencies": ["<!(node -e \"require('node-addon-api').gyp\")"],
      "cflags!": ["-fno-exceptions"],
      "cflags_cc!": ["-fno-exceptions"],
      "defines": ["NAPI_DISABLE_CPP_EXCEPTIONS"]
    }
  ]
}
