def read_file(file_input):
	with open(file_input) as f:
		output = f.read().split()
		return output


def write_list(file_input, file_output):
	with open(file_input) as f:
		output = f.read().split()
		with open(file_output, "w") as f:
			for line in output:
				f.write(line + '\n')



def write_list_sort(file_input, file_output):
	with open(file_input) as f:
		output = f.read().split()
		output.sort()
		with open(file_output, "w") as f:
			for line in output:
				f.write(line + '\n')


def write_list_cleansort(file_input, file_output):
	with open(file_input) as f:
		string = []
		output = f.read().split()
		for i in output:
			i = i.lower()
			i = i.replace("(", "")
			i = i.replace(")", "")
			i = i.replace(".", "")
			i = i.replace(",", "")
			string.append(i)
		string.sort()
		with open(file_output, "w") as f:
			for line in string:
				f.write(line.lower() + '\n')

		
				
		

