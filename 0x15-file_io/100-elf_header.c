#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * display_error - display error message and exit
 *
 * @msg: message to output
 *
 * Return: nothing
 */
void display_error(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(98);
}

int open_file(const char* filename)
{
	int fdesc;

	fdesc = open(filename, O_RDONLY);
	if (fdesc == -1)
		print_error("Failed to open file");
	return (fdesc);
}


ssize_t read_file(int fd, void* buf, size_t count)
{
	ssize_t n = read(fd, buf, count);

	if (n == -1)
		print_error("Failed to read file");
	return (n);

}

Elf64_Ehdr* read_elf_header(const char* filename)
{
	int fdesc;
	char buf[BUF_SIZE];
	ssize_t n;
	Elf64_Ehdr* ehdr;

	fdesc = open_file(filename);
	n = read_file(fdesc, buf, BUF_SIZE);

	close(fdesc);
	if (n < sizeof(Elf64_Ehdr))
		print_error("File too small to contain ELF header");

	ehdr = (Elf64_Ehdr*) buf;
	if (ehdr->e_ident[EI_MAG0] != ELFMAG0 ||
			ehdr->e_ident[EI_MAG1] != ELFMAG1 ||
			ehdr->e_ident[EI_MAG2] != ELFMAG2 ||
			ehdr->e_ident[EI_MAG3] != ELFMAG3)
		print_error("Not an ELF file");

	return (ehdr);

}


void print_magic(const Elf64_Ehdr* ehdr)
{
	printf("Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", ehdr->e_ident[i]);
	printf("\n");
}

void print_class(const Elf64_Ehdr* ehdr)
{
	printf("Class:                             %s\n",
			ehdr->e_ident[EI_CLASS] == ELFCLASS32 ?
			"ELF32" : "ELF64");
}


void print_data(const Elf64_Ehdr* ehdr)
{
	printf("Data:                              %s\n",
			ehdr->e_ident[EI_DATA] == ELFDATA2LSB 
		       	"2's complement, little endian" :
			"2's complement, big endian");
}


void print_version(const Elf64_Ehdr* ehdr)
{
	printf("Version:                           %d\n",
			ehdr->e_ident[EI_VERSION]);
}

void print_osabi(const Elf64_Ehdr* ehdr)
{
	printf("OS/ABI:                            ");
	switch (ehdr->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV: 
			printf("UNIX - System V\n");
				    break;
		case ELFOSABI_HPUX: printf("HP-UX\n");
				    break;
		case ELFOSABI_NETBSD: printf("NetBSD\n");
				      break;

	}
}
