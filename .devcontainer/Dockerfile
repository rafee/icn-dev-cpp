#-------------------------------------------------------------------------------------------------------------
# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License. See https://go.microsoft.com/fwlink/?linkid=2090316 for license information.
#-------------------------------------------------------------------------------------------------------------

# To fully customize the contents of this image, use the following Dockerfile as a base and add the RUN statement from this file:
# https://github.com/microsoft/vscode-dev-containers/blob/v0.112.0/containers/debian-10-git/.devcontainer/Dockerfile
FROM rafee1344/ubuntu:16.04

# This Dockerfile's base image has a non-root user with sudo access. Use the "remoteUser"
# property in devcontainer.json to use it. On Linux, the container user's GID/UIDs
# will be updated to match your local UID/GID (when using the dockerFile property).
# See https://aka.ms/vscode-remote/containers/non-root-user for details.
ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Avoid warnings by switching to noninteractive
ENV DEBIAN_FRONTEND=noninteractive

# Configure apt and install packages
RUN apt-get update \
    #
    # Install C++ tools
    && apt-get -y install build-essential cmake cppcheck valgrind libcpprest-dev libboost-all-dev pkg-config libsqlite3-dev\
    #
    # Clone ndn-cxx and install version suitable for 16.04
    && git clone https://github.com/named-data/ndn-cxx \
    && cd ndn-cxx \
    && git checkout 9603325ba6e35a0b985c77e074b77e3a3e7030ea \
    && ./waf configure \
    && ./waf \
    && ./waf install \
    && ldconfig \
    #
    # Clean ndn-cxx
    && cd .. && rm -rf ndn-cxx \
    #
    # Clean up
    && apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

# # [Optional] Set the default user. Omit if you want to keep the default as root.
# USER $USERNAME

#
# Clone blackadder and install version suitable for 16.04
RUN git clone https://github.com/rafee/blackadder \
    && cd blackadder \
    && apt-get update \
    && ./make-all-clean.sh \
    && cd .. && rm -rf blackadder \
    # Clean up
    && apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

# Switch back to dialog for any ad-hoc use of apt-get
ENV DEBIAN_FRONTEND=dialog
