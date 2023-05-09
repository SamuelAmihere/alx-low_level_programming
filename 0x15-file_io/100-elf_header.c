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

/**
 * read_elf_header - read ELF header information into a struct
 *
 * @fdesc: file descriptor
 * @elf_header: ELF header information
 *
 * Return: nothing
 */
void read_elf_header(int fdesc, Elf64_Ehdr *elf_header)
{
	if (read(fdesc, elf_header, sizeof(Elf64_Ehdr)) !=
			sizeof(Elf64_Ehdr))
		display_error("Error reading ELF header");
}

/**
 * display_elf_header_info - display the ELF header information
 *
 * @elf_header: elf header pointer
 *
 * Return: nothing
 */
void display_elf_header_info(Elf64_Ehdr *elf_header)
{
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", elf_header->e_ident[i]);
	}

	printf("\n");

	printf("  Class:                             %s\n",
			elf_header->e_ident[EI_CLASS] == ELFCLASS64 ?
			"ELF64" : "Unknown");
	printf("  Data:                              %s\n",
			elf_header->e_ident[EI_DATA] == ELFDATA2LSB ?
			"2's complement, little endian" : "Unknown");
	printf("  Version:                           %d (current)\n",
			elf_header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %d\n",
			elf_header->e_ident[EI_OSABI]);
	printf("  ABI Version:                       %d\n",
			elf_header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %d\n",
			elf_header->e_type);
	printf("  Entry point address:               0x%lx\n",
			elf_header->e_entry);
}

/**
 * main - entry point
 *
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0 on Success
 */
int main(int argc, char *argv[])
{
	int fdesc;
	Elf64_Ehdr elf_header;

	if (argc != 2)
		display_error("Usage: elf_header elf_filename");

	fdesc = open(argv[1], O_RDONLY);
	if (fdesc == -1)
		display_error("Error opening file");

	read_elf_header(fdesc, &elf_header);

	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
			elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
			elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
			elf_header.e_ident[EI_MAG3] != ELFMAG3)
	{
		display_error("Error: Not an ELF file");
	}

	printf("ELF Header:\n");
	display_elf_header_info(&elf_header);

	if (close(fdesc) == -1)
		display_error("Error closing file");

	return (0);
}
