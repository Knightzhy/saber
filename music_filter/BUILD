load("@rules_cc//cc:defs.bzl", "cc_binary")
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
  name="load_file",
  srcs=["load_file.cpp"],
  hdrs=["load_file.h", "types.h"],
)

cc_library(
  name="remove_file",
  srcs=["remove_file.cpp"],
  hdrs=["remove_file.h"],
)

cc_binary(
  name="music_filter",
  srcs=["test.cpp"],
  deps=[":load_file", ":remove_file"],
)