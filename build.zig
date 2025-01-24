const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const exe = b.addExecutable(.{ .name = "sssh", .target = target });

    exe.addCSourceFiles(.{ .files = &.{ "src/main.c", "src/libcstring/src/c_string.c", "src/linenoise/linenoise.c" } });
    exe.linkLibC();

    b.installArtifact(exe);
}
