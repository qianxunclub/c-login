package(default_visibility = ["//visibility:public"])

load("@rules_cc//cc:defs.bzl", "cc_binary","cc_library", "cc_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

cc_binary(
    name = "c_login",
    srcs = [
        "main/Main.cpp",
        ],
    deps = [
        ":core",
        ":pb",
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
        "protos/**/*.cc",
        ]),
    hdrs = glob([
        "model/**/*.h",
        "repository/**/*.h",
        "service/**/*.h",
        "utils/**/*.h",
        "base/**/*.h",
        "config/**/*.h",
        "protos/**/*.h",
        ]),
    deps = [
        ":cc_proto",
        ":libs",
        ":pb",
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
    name = "pb",
    srcs = [
        'protos/login.grpc.pb.cc', 
        'protos/login.pb.cc', 
    ],
    hdrs = [
        'protos/login.grpc.pb.h',
        'protos/login.pb.h',
    ],
    deps = [
        '@com_google_protobuf//:protobuf',
        '@com_github_grpc_grpc//:grpc++',
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "libs",
    deps = [
        ":mysql",
        ":json",
        ":grpc",
        ":hiredis",
        ":protobuf",
        ":protoc",
        ":cipher",
    ],
)

cc_library(
    name = "mysql",
    srcs = glob([
        "libs/lib/libmariadb.dylib"
        ]),
    hdrs = glob(["libs/mysql/**/*.h"]),
    includes = glob(["libs/mysql"]),
    visibility = ["//visibility:public"]
)

cc_library(
    name = "cipher",
    srcs = glob(["libs/cipher/**/*.cpp","libs/cipher/**/*.cc"]),
    hdrs = glob(["libs/cipher/**/*.h"]),
    includes = glob(["libs/cipher"]),
    visibility = ["//visibility:public"]
)

cc_library(
    name = "grpc",
    srcs = glob([
        "libs/lib/libgrpc.dylib"
        ]),
    hdrs = glob(["libs/grpc/**/*.h"]),
    includes = glob(["libs/grpc"]),
    visibility = ["//visibility:public"]
)

cc_library(
    name = "hiredis",
    srcs = glob([
        "libs/lib/libhiredis.dylib"
        ]),
    hdrs = glob(["libs/hiredis/**/*.h"]),
    includes = glob(["libs/hiredis"]),
    visibility = ["//visibility:public"]
)

cc_library(
    name = "json",
    srcs = glob([
        "libs/lib/libjsoncpp.dylib"
        ]),
    hdrs = glob(["libs/json/**/*.h"]),
    includes = glob(["libs/json"]),
    visibility = ["//visibility:public"]
)

cc_library(
    name = "protobuf",
    srcs = glob([
        "libs/lib/libprotobuf.dylib"
        ]),
    hdrs = glob(["libs/google/**/*.h"]),
    includes = glob(["libs/google"]),
    visibility = ["//visibility:public"]
)

cc_library(
    name = "protoc",
    srcs = glob([
        "libs/lib/libprotoc.dylib"
        ]),
    visibility = ["//visibility:public"]
)