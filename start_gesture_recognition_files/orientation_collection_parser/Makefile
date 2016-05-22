all: combined_orientation_parser orientation_parser

combined_orientation_parser: combined_orientation_parser.c
	 	gcc -o combined_orientation_parser combined_orientation_parser.c	

orientation_parser: orientation_parser.c
		gcc -o orientation_parser orientation_parser.c

clean:
		rm -rf combined_orientation_parser
		rm -rf orientation_parser
