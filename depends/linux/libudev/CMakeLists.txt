cmake_minimum_required(VERSION 3.5)
project(libudev)

include(ExternalProject)

ExternalProject_Add(
    libudev
    SOURCE_DIR          ${CMAKE_SOURCE_DIR}
    CONFIGURE_COMMAND   <SOURCE_DIR>/autogen.sh
    COMMAND             <SOURCE_DIR>/configure
                            --prefix=${CMAKE_INSTALL_PREFIX}
                            --enable-static
                            --disable-shared
                            --with-pic
                            --enable-introspection=no
                            --disable-programs
                            --disable-blkid
                            --disable-selinux
                            --disable-manpages
                            --disable-kmod
                            --disable-mtd_probe
    INSTALL_COMMAND     ""
    BUILD_IN_SOURCE     1
)

install(CODE "execute_process(COMMAND make install WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})")
