// Allows to access metadata (e.g. type, owner, permission, size, date)
// Used with dirent.h to list files

/*
Main struct
struct stat {
    dev_t     st_dev;     // ID do dispositivo (disco/partição)
    ino_t     st_ino;     // Número do inode (ID único no filesystem, como em dirent)
    mode_t    st_mode;    // Modo: tipo + permissões (ex.: arquivo regular? diretório?)
    nlink_t   st_nlink;   // Número de hard links
    uid_t     st_uid;     // ID do usuário dono
    gid_t     st_gid;     // ID do grupo dono
    dev_t     st_rdev;    // ID do dispositivo especial (para arquivos de dispositivo)
    off_t     st_size;    // Tamanho em bytes (para arquivos; para dirs, tamanho do dir entry)
    blksize_t st_blksize; // Tamanho ótimo de bloco para I/O
    blkcnt_t  st_blocks;  // Número de blocos alocados
    time_t    st_atime;   // Tempo de último acesso (segundos desde epoch, 1970)
    time_t    st_mtime;   // Tempo de última modificação do conteúdo
    time_t    st_ctime;   // Tempo de última mudança de status (ex.: permissões, dono)
    // Campos extras em alguns sistemas: st_birthtime (data de criação real), mas não portátil
};

st_mode:
- S_ISREG(st_mode) → regular file?
- S_ISDIR(st_mode) → directory?
- S_ISLNK(st_mode) → link?
- S_ISFIFO(st_mode) → FIFO (pipe)?

st_size → file's size
st_ino → Unique ID

time_t → long int (seconds)
Convert to legible date w/: 
- ctime(&st.st_mtime)
- localtime() + strftime()


*/