{
  "targets": [
    {
      "target_name": "node-api-tuts",
      "sources": ["addons/addon.cpp"],
      "include_dirs": [
        "<!(node -p \"require('node-addon-api').include\")"
      ],
      "cflags": ["-std=c++17"],
      "cflags_cc": ["-std=c++17"]
    }
  ]
}