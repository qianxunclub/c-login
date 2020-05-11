load("@rules_cc//cc:defs.bzl", "cc_binary","cc_library")
package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "c_login",
    srcs = [
        "main/Main.cpp"
        ],
    deps = [
        ":utils",
    ],
)

cc_library(
    name = "proto",
    srcs = ["protos/login.proto"],
)

cc_library(
    name = "model",
    srcs = glob(["model/**/*.cpp"]),
    hdrs = glob(["model/**/*.h"]),
)

cc_library(
    name = "repository",
    srcs = glob(["repository/**/*.cpp"]),
    hdrs = glob(["repository/**/*.h"]),
    deps = [
        ":model",
        ":utils",
        ":base"
    ]
)

cc_library(
    name = "service",
    srcs = glob(["service/**/*.cpp"]),
    hdrs = glob(["service/**/*.h"]),
    deps = [
        ":repository"
    ]
)

cc_library(
    name = "utils",
    srcs = glob(["utils/**/*.cpp"]),
    hdrs = glob(["utils/**/*.h"]),
    deps = [
        ":base",
        ":cipher",
    ],
)


cc_library(
    name = "base",
    srcs = glob(["base/**/*.cpp"]),
    hdrs = glob(["base/**/*.h"]),
    deps = [
        ":config",
        ":hiredis",
        ":mysql"
    ],

)

cc_library(
    name = "config",
    srcs = glob(["config/**/*.cpp"]),
    hdrs = glob(["config/**/*.h"]),
    deps = [
        ":json"
    ],
    data = ["//resource:config.json"],
)

cc_library(
    name = "cipher",
    hdrs = glob(["libs/cipher/**/*.h"]),
)
cc_library(
    name = "json",
    hdrs = glob(["libs/json/**/*.h"]),
)
cc_library(
    name = "hiredis",
    hdrs = glob(["libs/hiredis/**/*.h"]),
)

cc_library(
    name = "mysql",
    hdrs = glob(["libs/mysql/**/*.h"]),
)
