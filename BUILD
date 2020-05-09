package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "c_login",
    srcs = [
        "main/Main.cpp"
        ],
    deps = [
        ":libs",
        ":utils",
        ":model",
        ":app_config",
        ":base",
    ],
)

cc_library(
    name = "libs",
    srcs = [
        "libs/cipher/aes.cpp",
        "libs/cipher/aes_encryptor.cpp",
        "libs/cipher/md5.cc",
        "libs/cipher/sha256.cc",
    ],
    hdrs = [
		"libs/cipher/aes.h",
		"libs/cipher/aes_encryptor.h",
		"libs/cipher/md5.h",
		"libs/cipher/sha256.h",
    ],
    deps = [
    ],
)

cc_library(
    name = "model",
    srcs = [
        "model/User.cpp",
        "model/Result.cpp",
    ],
    hdrs = [
		"model/User.h",
		"model/Result.h",
    ],
)
cc_import(
    name = "cipher",
    hdrs = ["libs/cipher/aes_encryptor.h","libs/cipher/aes.h","libs/cipher/md5.h","libs/cipher/sha256.h"],
)

cc_library(
    name = "utils",
    srcs = [
        "utils/Common.cpp",
    ],
    hdrs = [
		"utils/Common.h",
    ],
    deps = [
        ":libs",
        ":base",
        ":cipher",
    ],
)


cc_library(
    name = "base",
    srcs = [
        "base/Database.cpp",
        "base/Redis.cpp",
    ],
    hdrs = [
		"base/Database.h",
		"base/Redis.h",
    ],
    deps = [
        ":app_config",
        ":hiredis"
    ],

)
cc_import(
    name = "json",
    hdrs = [
        "libs/json/autolink.h",
        "libs/json/config.h",
        "libs/json/features.h",
        "libs/json/forwards.h",
        "libs/json/json.h",
        "libs/json/reader.h",
        "libs/json/value.h",
        "libs/json/writer.h",
    ],

)

cc_library(
    name = "app_config",
    srcs = [
        "config/AppConfig.cpp",
    ],
    hdrs = [
		"config/AppConfig.h",
    ],
    deps = [
        ":json"
    ],
)

cc_import(
    name = "hiredis",
    hdrs = [
        "libs/hiredis/hiredis.h"
        ],
)