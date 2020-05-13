load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_proto",
    strip_prefix = "rules_proto-master",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/master.tar.gz",
        "https://github.com/bazelbuild/rules_proto/archive/master.tar.gz",
    ],
)
load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
rules_proto_dependencies()
rules_proto_toolchains()


http_archive(
    name = "com_github_grpc_grpc",
    strip_prefix = "grpc-master",
    urls = [
        "https://github.com/grpc/grpc/archive/master.zip",
    ],
    
)
load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
grpc_deps()
load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")
grpc_extra_deps()