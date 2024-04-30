# FreeBSD ports

It's my (@er2off) ports overlay with some ports that can be used by
any FreeBSD user.
All of these ports are planned to be merged into upstream in future.

# Usage

Just clone this repo, `cd` to needed port and `make install` it.

```sh
$ git clone https://github.com/er2off/freebsd-ports
$ cd net-im/armcord
$ sudo make install # or other tool to go to root, I prefer doas
```

If you prefer poudriere instead, it's also possible:

```sh
poudriere ports -c -m git+http -p er2ports -U github.com/er2off/freebsd-ports
poudriere bulk -j 140amd64 -O er2ports # -f pkglist.txt or simply package names
```

# Testing

I don't always test my ports build in poudriere because sometimes I'm lazy
to wait until everything will be built. So if you found any issues, tell me.
