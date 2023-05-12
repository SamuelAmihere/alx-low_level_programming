#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

#define BUF_SIZE 1024

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


/**
 * open_file - opens a file
 *
 * @filename: name of a file
 *
 * Return: integer
 */
int open_file(const char *filename)
{
	int fdesc;

	fdesc = open(filename, O_RDONLY);
	if (fdesc == -1)
		printf("Failed to open file");
	return (fdesc);
}

/**
 * read_file - reads file
 *
 * @fdesc: file descriptor
 * @buf: buffer
 * @count: buffer counts
 *
 * Return: number of buffer read
 */
ssize_t read_file(int fdesc, void *buf, size_t count)
{
	ssize_t n = read(fdesc, buf, count);

	if (n == -1)
		printf("Failed to read file");
	return (n);

}

/**
 * read_elf_header - reads elf header
 *
 * @filename: filename
 * Return: Elf64_Ehdr pointer
 */
Elf64_Ehdr *read_elf_header(const char *filename)
{
	int fdesc;
	char buf[BUF_SIZE];
	ssize_t n;
	Elf64_Ehdr *ehdr;

	fdesc = open_file(filename);
	n = read_file(fdesc, buf, BUF_SIZE);

	close(fdesc);
	if (n < sizeof(Elf64_Ehdr))
		printf("File too small to contain ELF header");

	ehdr = (Elf64_Ehdr *) buf;
	if (ehdr->e_ident[EI_MAG0] != ELFMAG0 ||
			ehdr->e_ident[EI_MAG1] != ELFMAG1 ||
			ehdr->e_ident[EI_MAG2] != ELFMAG2 ||
			ehdr->e_ident[EI_MAG3] != ELFMAG3)
		printf("Not an ELF file");

	return (ehdr);

}

/**
 * print_magic - prints magic
 *
 * @ehdr: a pointer to an Elf64_Ehdr structure
 * Return: nothing
 */
void print_magic(const Elf64_Ehdr *ehdr)
{
	printf("Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", ehdr->e_ident[i]);
	printf("\n");
}


/**
 * print_class - prints class
 *
 * @ehdr: a pointer to an Elf64_Ehdr structure
 * Return: nothing
 */
void print_class(const Elf64_Ehdr *ehdr)
{
	printf("Class:                             %s\n",
			ehdr->e_ident[EI_CLASS] == ELFCLASS32 ?
			"ELF32" : "ELF64");
}

/**
 * print_data - prints data
 *
 * @ehdr: a pointer to an Elf64_Ehdr structure
 * Return: nothing
 */

void print_data(const Elf64_Ehdr *ehdr)
{
	printf("Data:					%s\n",
			ehdr->e_ident[EI_DATA] == ELFDATA2LSB ?
			"2's complement, little endian" :
			"2's complement, big endian");
}

/**
 * print_version - prints version
 *
 * @ehdr: a pointer to an Elf64_Ehdr structure
 * Return: nothing
 */

void print_version(const Elf64_Ehdr *ehdr)
{
	printf("Version:                           %d\n",
			ehdr->e_ident[EI_VERSION]);
}


/**
 * print_osabi- prints ab
 *
 * @ehdr: a pointer to an Elf64_Ehdr structure
 * Return: nothing
 */
void print_osabi(const Elf64_Ehdr *ehdr)
{
	printf("OS/ABI:                            ");
	switch (ehdr->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Solaris\n");
			break;
		case ELFOSABI_AIX:
			printf("AIX\n");
			break;
		case ELFOSABI_IRIX:
			printf("IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("Compaq TRU64 UNIX\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone (embedded) application\n");
			break;
		default:
			printf("<unknown>\n");
			break;

	}
}


/**
 * print_abi_version - prints abi version
 *
 * @ehdr: a pointer to an Elf64_Ehdr structure
 * Return: nothing
 */
void print_abi_version(const Elf64_Ehdr *ehdr)
{
	printf("ABI Version: %d\n", ehdr->e_ident[EI_ABIVERSION]);
}


/**
 * print_type - prints type
 *
 * @ehdr: a pointer to an Elf64_Ehdr structure
 * Return: nothing
 */
void print_type(const Elf64_Ehdr *ehdr)
{
	printf("Type: ");
	switch (ehdr->e_type)
	{
		case ET_NONE:
			printf("NONE (No file type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown>\n");
			break;
	}
}

/**
 * print_entry_point - prints entry point
 *
 * @ehdr: a pointer to an Elf64_Ehdr structure
 *
 * Return: nothing
 */
void print_entry_point(const Elf64_Ehdr *ehdr)
{
	printf("Entry point address: 0x%lx\n", (unsigned long) ehdr->e_entry);
}

/**
 * main - entry point to main
 *
 * @argc: number of args
 * @argv: args
 *
 * Return: 0on Success
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		printf("Usage: elf_header elf_filename");
	const char *filename = argv[1];
	Elf64_Ehdr *ehdr = read_elf_header(filename);

	print_magic(ehdr);
	print_class(ehdr);
	print_data(ehdr);
	print_version(ehdr);
	print_osabi(ehdr);
	print_abi_version(ehdr);
	print_type(ehdr);
	print_entry_point(ehdr);
	return (0);
}
