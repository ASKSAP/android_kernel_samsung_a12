#!/bin/bash

export CROSS_COMPILE=$(pwd)/../PLATFORM/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/aarch64-linux-android-
export CC=$(pwd)/../PLATFORM/prebuilts/clang/host/linux-x86/clang-r353983c/bin/clang
export CLANG_TRIPLE=aarch64-linux-gnu-
export ARCH=arm64

export KCFLAGS=-w
export CONFIG_SECTION_MISMATCH_WARN_ONLY=y

make -C $(pwd) O=$(pwd)/out KCFLAGS=-w CONFIG_SECTION_MISMATCH_WARN_ONLY=y a12_defconfig
make -C $(pwd) O=$(pwd)/out KCFLAGS=-w CONFIG_SECTION_MISMATCH_WARN_ONLY=y -j16

cp out/arch/arm64/boot/Image $(pwd)/arch/arm64/boot/Image