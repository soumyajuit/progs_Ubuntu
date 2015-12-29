
def swap(str_list, idx_1, idx_2):
	_t = str_list[idx_1];
	str_list[idx_1] = str_list[idx_2];
	str_list[idx_2] = _t;

def rev_str(str_list):
	str_len = len(str_list);
	for i in range(str_len/2):
		swap(str_list, i, str_len-1-i);
	
	return str_list;


def rev_my_str():
	inp_str = raw_input();
	inp_list = inp_str.split(" ");
	print "len is ", len(inp_list);
	out_str = rev_str(inp_list);
	for i in range(len(out_str)):
		print out_str[i];


rev_my_str();
