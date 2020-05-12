FROM ubuntu:18.04 AS downloader
WORKDIR /download
ARG ROOT_IMAGE=https://root.cern/download/root_v6.20.04.Linux-ubuntu18-x86_64-gcc7.5.tar.gz
ARG PYTHIA_IMAGE=http://home.thep.lu.se/~torbjorn/pythia8/pythia8244.tgz
ARG PYTHIA_DIRNAME=pythia8244
RUN apt update && apt-get install -y wget
RUN wget -q -O root6.tag.gz $ROOT_IMAGE && tar -xzf root6.tag.gz && rm root6.tag.gz
RUN wget -q -O pythia8.tgz $PYTHIA_IMAGE && tar -xzf pythia8.tgz && rm pythia8.tgz
RUN mv $PYTHIA_DIRNAME pythia8

FROM ubuntu:18.04
WORKDIR /software
COPY --from=downloader download/root root
COPY --from=downloader download/pythia8 pythia8
RUN apt update && apt-get install -y git dpkg-dev cmake g++ gcc binutils libx11-dev libxpm-dev libxft-dev libxext-dev
RUN echo "source /software/root/bin/thisroot.sh ">>/root/.bashrc
RUN cd pythia8 && ./configure --enable-optdebug --enable-shared && make
CMD /bin/bash -c 
#CMD /bin/bash -c "source /software/root/bin/thisroot.sh; root -b"