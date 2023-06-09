#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * display_error - display error message and exit
 *
 * @msg: message to output
 * @file: filename
 * @code: exit code
 *
 * Return: nothing
 */
void display_error(char *msg, char *file, int code)
{
	dprintf(STDERR_FILENO, "Error: %s %s\n",
				msg, file);
	exit(code);
}

/**
 * inspect_elf - Verifies if a file is an ELF header file.
 *
 * @ehdr: A pointer to elf  magic numbers.
 *
 * Returns: Nothing - exit code 98.
 */
void inspect_elf(unsigned char *ehdr)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (ehdr[i] != 127 &&
				ehdr[i] != 'F' &&
				ehdr[i] != 'E' &&
				ehdr[i] != 'L')
			display_error("Not an ELF file", "", 98);
		i++;
	}
}


/**
 * print_magic - prints magic
 *
 * @ehdr: a pointer to an Elf64_Ehdr structure
 * Return: nothing
 */
void print_magic(unsigned char *ehdr)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", ehdr[i]);
		if (i != EI_NIDENT - 1)
			printf(" ");
		else
			printf("\n");
	}
}

/**
 * print_data - prints data
 *
 * @ehdr: a pointer to an Elf64_Ehdr structure
 * Return: nothing
 */

void print_data(unsigned char *ehdr)
{
	printf("  Data:                              ");

	switch (ehdr[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian");
			break;
		case ELFDATANONE:
			printf("none");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian");
			break;
		default:
			printf("<unknown: %x>", ehdr[EI_CLASS]);
	}
	printf("\n");
}

/**
 * print_elftype - Prints ELF headeer file type
 * @ehdr: a pointer to an Elf64_Ehdr structure
 * @type: ELF type address
 * Return: Nothing
 */
void print_elftype(unsigned char *ehdr, unsigned long int type)
{
	if (ehdr[EI_DATA] == ELFDATA2MSB)
		type = type >> 8;
	printf("  Type:                              ");

	switch (type)
	{
		case ET_EXEC:
			printf("EXEC (Executable file)");
			break;
		case ET_CORE:
			printf("CORE (Core file)");
			break;
		case ET_REL:
			printf("REL (Relocatable file)");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)");
			break;
		case ET_NONE:
			printf("NONE (None)");
			break;
		default:
			printf("<unknown: %x>", (unsigned int)type);
	}
	printf("\n");
}

/**
 * print_class - prints class
 *
 * @ehdr: a pointer to an Elf64_Ehdr structure
 * Return: nothing
 */
void print_class(unsigned char *ehdr)
{
	printf("  Class:                             ");

	switch (ehdr[EI_CLASS])
	{
		case ELFCLASS64:
			printf("ELF64");
			break;
		case ELFCLASS32:
			printf("ELF32");
			break;
		case ELFCLASSNONE:
			printf("none");
			break;
		default:
			printf("<unknown: %x>", ehdr[EI_CLASS]);
	}
	printf("\n");
}


/**
 * print_vers - prints version
 *
 * @ehdr: a pointer to an Elf64_Ehdr structure
 * Return: nothing
 */

void print_vers(unsigned char *ehdr)
{
	printf("  Version:                           %d",
			ehdr[EI_VERSION]);

	switch (ehdr[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)");
			break;
		case EV_NONE:
			printf("0");
			break;
		default:
			break;
	}
	printf("\n");
}


/**
 * print_os - prints ab
 *
 * @ehdr: a pointer to an Elf64_Ehdr structure
 * Return: nothing
 */
void print_os(unsigned char *ehdr)
{
	printf("  OS/ABI:                            ");
	switch (ehdr[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linu\nx");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone app\n");
			break;
		default:
			printf("<unknown: %x>\n", ehdr[EI_OSABI]);
			break;
	}
}

/**
 * print_abi_version - prints abi version
 *
 * @ehdr: a pointer to an Elf64_Ehdr structure
 * Return: nothing
 */
void print_abi_version(unsigned char *ehdr)
{
	printf("  ABI Version:                       %d\n",
			ehdr[EI_ABIVERSION]);
}

/**
 * print_entry_point - prints entry point
 *
 * @ehdr: a pointer to an Elf64_Ehdr structure
 * @entry: ELF entry point address.
 *
 * Return: nothing
 */
void print_entry_point(unsigned char *ehdr, unsigned long int entry)
{
	printf("  Entry point address:               ");

	if (ehdr[EI_DATA] == ELFDATA2MSB)
	{
		entry = ((entry << 8) & 0xFF00FF00) |
			((entry >> 8) & 0xFF00FF);
		entry = (entry << 16) | (entry >> 16);
	}
	if (ehdr[EI_CLASS] != ELFCLASS32)
		printf("%#lx\n", entry);
	else
		printf("%#x\n", (unsigned int)entry);
}

/**
 * open_file - open a file
 *
 * @filename: file name
 * @flags: flag for file permissions
 * @mode: file mode
 *
 * Return: file descriptor
 */
int open_file(char *filename, int flags, mode_t mode)
{
	int fdesc;

	if (mode == 0)
		fdesc = open(filename, flags);
	else
		fdesc = open(filename, flags, mode);
	return (fdesc);
}

/**
 * close_file - close a file
 *
 * @fdesc: file descriptor
 *
 * Return: nothing
 */
void close_file(int fdesc)
{
	int fclose;

	fclose = close(fdesc);
	if (fclose == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n",
				fdesc);
		exit(98);
	}
}

/**
 * main - entry point to main
 *
 * @argc: number of args
 * @argv: args
 *
 * Return: 0 on Success
 */
int main(int __attribute__((__unused__)) argc, char **argv)
{
	Elf64_Ehdr *elf_header;
	int src, bytes_r;
	char *sr = argv[1], *err_msg = "Can't read file";

	src = open_file(sr, O_RDONLY, 0);
	if (src < 0)
		display_error(err_msg, sr, 98);
	elf_header = malloc(sizeof(Elf64_Ehdr));
	if (!elf_header)
	{
		close_file(src);
		display_error(err_msg, sr, 98);
	}
	bytes_r = read(src, elf_header, sizeof(Elf64_Ehdr));
	if (bytes_r < 0)
	{
		free(elf_header);
		close_file(src);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n",
				sr);
		exit(98);
	}
	inspect_elf(elf_header->e_ident);

	printf("ELF Header:\n");

	print_magic(elf_header->e_ident);
	print_class(elf_header->e_ident);
	print_data(elf_header->e_ident);
	print_vers(elf_header->e_ident);
	print_os(elf_header->e_ident);
	print_abi_version(elf_header->e_ident);
	print_elftype(elf_header->e_ident, elf_header->e_type);
	print_entry_point(elf_header->e_ident, elf_header->e_entry);

	free(elf_header);
	close_file(src);
	return (0);
}
