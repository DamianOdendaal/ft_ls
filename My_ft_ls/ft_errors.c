      /* E2BIG           Argument list too long (POSIX.1-2001).

      // EACCES          Permission denied (POSIX.1-2001).

       EADDRINUSE      Address already in use (POSIX.1-2001).

       EADDRNOTAVAIL   Address not available (POSIX.1-2001).

       EAFNOSUPPORT    Address family not supported (POSIX.1-2001).

       EAGAIN          Resource temporarily unavailable (may be the same
                       value as EWOULDBLOCK) (POSIX.1-2001).

       EALREADY        Connection already in progress (POSIX.1-2001).

       EBADE           Invalid exchange.

       EBADF           Bad file descriptor (POSIX.1-2001).      // scope this one

       EBADFD          File descriptor in bad state.

       EBADMSG         Bad message (POSIX.1-2001).          //here too

       EBADR           Invalid request descriptor.

       EBADRQC         Invalid request code.

       EBADSLT         Invalid slot.

       EBUSY           Device or resource busy (POSIX.1-2001).

       ECANCELED       Operation canceled (POSIX.1-2001).

       ECHILD          No child processes (POSIX.1-2001).

       ECHRNG          Channel number out of range.

       ECOMM           Communication error on send.

       ECONNABORTED    Connection aborted (POSIX.1-2001).

       ECONNREFUSED    Connection refused (POSIX.1-2001).

       ECONNRESET      Connection reset (POSIX.1-2001).

       EDEADLK         Resource deadlock avoided (POSIX.1-2001).        //here

       EDEADLOCK       Synonym for EDEADLK.

       EDESTADDRREQ    Destination address required (POSIX.1-2001).     //here

       EDOM            Mathematics argument out of domain of function
                       (POSIX.1, C99).

       EDQUOT          Disk quota exceeded (POSIX.1-2001).

       EEXIST          File exists (POSIX.1-2001).          //here

       EFAULT          Bad address (POSIX.1-2001).

       EFBIG           File too large (POSIX.1-2001).       //here

       EHOSTDOWN       Host is down.

       EHOSTUNREACH    Host is unreachable (POSIX.1-2001).

       EHWPOISON       Memory page has hardware error.

       EIDRM           Identifier removed (POSIX.1-2001).

       EILSEQ          Invalid or incomplete multibyte or wide character
                       (POSIX.1, C99).

                       The text shown here is the glibc error description;
                       in POSIX.1, this error is described as "Illegal byte
                       sequence".

       EINPROGRESS     Operation in progress (POSIX.1-2001).

       EINTR           Interrupted function call (POSIX.1-2001); see
                       signal(7).

       EINVAL          Invalid argument (POSIX.1-2001).     //here

       EIO             Input/output error (POSIX.1-2001).

       EISCONN         Socket is connected (POSIX.1-2001).

       EISDIR          Is a directory (POSIX.1-2001).       //here

       EISNAM          Is a named type file.

       EKEYEXPIRED     Key has expired.

       EKEYREJECTED    Key was rejected by service.

       EKEYREVOKED     Key has been revoked.

       EL2HLT          Level 2 halted.      //all of he level ones

       EL2NSYNC        Level 2 not synchronized.

       EL3HLT          Level 3 halted.

       EL3RST          Level 3 reset.

       ELIBACC         Cannot access a needed shared library.

       ELIBBAD         Accessing a corrupted shared library.

       ELIBMAX         Attempting to link in too many shared libraries.

       ELIBSCN         .lib section in a.out corrupted      //here

       ELIBEXEC        Cannot exec a shared library directly.

       ELNRANGE        Link number out of range.        //here

       ELOOP           Too many levels of symbolic links (POSIX.1-2001).

       EMEDIUMTYPE     Wrong medium type.

       EMFILE          Too many open files (POSIX.1-2001).  Commonly caused
                       by exceeding the RLIMIT_NOFILE resource limit
                       described in getrlimit(2).                               //here

       EMLINK          Too many links (POSIX.1-2001).

       EMSGSIZE        Message too long (POSIX.1-2001).         //here

       EMULTIHOP       Multihop attempted (POSIX.1-2001).

       ENAMETOOLONG    Filename too long (POSIX.1-2001).

       ENETDOWN        Network is down (POSIX.1-2001).

       ENETRESET       Connection aborted by network (POSIX.1-2001).

       ENETUNREACH     Network unreachable (POSIX.1-2001).

       ENFILE          Too many open files in system (POSIX.1-2001).  On
                       Linux, this is probably a result of encountering the
                       /proc/sys/fs/file-max limit (see proc(5)).

       ENOANO          No anode.

       ENOBUFS         No buffer space available (POSIX.1 (XSI STREAMS
                       option)).

       ENODATA         No message is available on the STREAM head read queue
                       (POSIX.1-2001).

       ENODEV          No such device (POSIX.1-2001).

       ENOENT          No such file or directory (POSIX.1-2001).        //here

                       Typically, this error results when a specified path‐
                       name does not exist, or one of the components in the
                       directory prefix of a pathname does not exist, or the
                       specified pathname is a dangling symbolic link.

       ENOEXEC         Exec format error (POSIX.1-2001).

       ENOKEY          Required key not available.          //here

       ENOLCK          No locks available (POSIX.1-2001).

       ENOLINK         Link has been severed (POSIX.1-2001).

       ENOMEDIUM       No medium found.

       ENOMEM          Not enough space/cannot allocate memory          //here
                       (POSIX.1-2001).

       ENOMSG          No message of the desired type (POSIX.1-2001).

       ENONET          Machine is not on the network.

       ENOPKG          Package not installed.

       ENOPROTOOPT     Protocol not available (POSIX.1-2001).

       ENOSPC          No space left on device (POSIX.1-2001).

       ENOSR           No STREAM resources (POSIX.1 (XSI STREAMS option)).          //here and all streams

       ENOSTR          Not a STREAM (POSIX.1 (XSI STREAMS option)).

       ENOSYS          Function not implemented (POSIX.1-2001).

       ENOTBLK         Block device required.           //here

       ENOTCONN        The socket is not connected (POSIX.1-2001).

       ENOTDIR         Not a directory (POSIX.1-2001).              //here

       ENOTEMPTY       Directory not empty (POSIX.1-2001).              //here

       ENOTRECOVERABLE State not recoverable (POSIX.1-2008).

       ENOTSOCK        Not a socket (POSIX.1-2001).

       ENOTSUP         Operation not supported (POSIX.1-2001).

       ENOTTY          Inappropriate I/O control operation (POSIX.1-2001).

       ENOTUNIQ        Name not unique on network.

       ENXIO           No such device or address (POSIX.1-2001).

       EOPNOTSUPP      Operation not supported on socket (POSIX.1-2001).

                       (ENOTSUP and EOPNOTSUPP have the same value on Linux,
                       but according to POSIX.1 these error values should be
                       distinct.)

       EOVERFLOW       Value too large to be stored in data type
                       (POSIX.1-2001).

       EOWNERDEAD      Owner died (POSIX.1-2008).

       EPERM           Operation not permitted (POSIX.1-2001).

       EPFNOSUPPORT    Protocol family not supported.

       EPIPE           Broken pipe (POSIX.1-2001).

       EPROTO          Protocol error (POSIX.1-2001).

       EPROTONOSUPPORT Protocol not supported (POSIX.1-2001).

       EPROTOTYPE      Protocol wrong type for socket (POSIX.1-2001).

       ERANGE          Result too large (POSIX.1, C99).

       EREMCHG         Remote address changed.

       EREMOTE         Object is remote.

       EREMOTEIO       Remote I/O error.

       ERESTART        Interrupted system call should be restarted.

       ERFKILL         Operation not possible due to RF-kill.

       EROFS           Read-only filesystem (POSIX.1-2001).

       ESHUTDOWN       Cannot send after transport endpoint shutdown.

       ESPIPE          Invalid seek (POSIX.1-2001).

       ESOCKTNOSUPPORT Socket type not supported.

       ESRCH           No such process (POSIX.1-2001).

       ESTALE          Stale file handle (POSIX.1-2001).

                       This error can occur for NFS and for other filesys‐
                       tems.

       ESTRPIPE        Streams pipe error.

       ETIME           Timer expired (POSIX.1 (XSI STREAMS option)).

                       (POSIX.1 says "STREAM ioctl(2) timeout".)

       ETIMEDOUT       Connection timed out (POSIX.1-2001).

       ETOOMANYREFS    Too many references: cannot splice.

       ETXTBSY         Text file busy (POSIX.1-2001).

       EUCLEAN         Structure needs cleaning.

       EUNATCH         Protocol driver not attached.

       EUSERS          Too many users.

       EWOULDBLOCK     Operation would block (may be same value as EAGAIN)
                       (POSIX.1-2001).

       EXDEV           Improper link (POSIX.1-2001).

       EXFULL          Exchange full.  */0
