package(default_visibility = ["//visibility:public"])

load("@rules_cc//cc:defs.bzl", "cc_binary","cc_library", "cc_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

cc_binary(
    name = "c_login",
    srcs = [
        "main/Main.cpp",
        "main/Main.h"
        ],
    deps = [
        ":core",
    ],
)

cc_library(
    name = "core",
    srcs = glob([
        "model/**/*.cpp",
        "repository/**/*.cpp",
        "service/**/*.cpp",
        "utils/**/*.cpp",
        "base/**/*.cpp",
        "config/**/*.cpp",
        ]),
    hdrs = glob([
        "model/**/*.h",
        "repository/**/*.h",
        "service/**/*.h",
        "utils/**/*.h",
        "base/**/*.h",
        "config/**/*.h",
        ]),
    deps = [
        ":cc_proto",
        ":json",
        ":cipher",
        ":hiredis",
        ":mysql",
    ],
    data = ["//resource:config.json"],
)

cc_library(
    name = "config",
    srcs = glob([
        "config/**/*.cpp",
        ]),
    hdrs = glob([
        "config/**/*.h",
        ]),
    deps = [
        ":json",
    ],
    data = ["//resource:config.json"],
)


proto_library(
    name = "proto",
    srcs = ["protos/login.proto"],
)

cc_proto_library(
	name = "cc_proto",
    deps = [":proto"],
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
