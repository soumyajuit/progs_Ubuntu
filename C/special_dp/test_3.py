import ctypes

print "hello world"

max_digits = 1024;
mod_max = 10L;
mod_max **= 9L;
mod_val = mod_max * 7; 


x=10;


def print_arr(digits, len):
	for i in range(len):
		for j in range(len):
			print "digits at :", i , j, digits[i][j];

def my_printfunc(myarg):
	str1 = "This not good";
	print "the length is:", len(str1)

def my_func1():
	list1 = ['soumya', 'poddar'];
	list2 = ['is', 'bogus'];
	list3 = [1, 2, 3, 4];
	list4 = list1 + list2;
	
	t_digits = [['' for x in range(max_digits)] for x in range(max_digits)];
	matrix1 = [[x for x in range(5)] for x in range(5)];

	num = 1234;
	t_digits[0][0] = str(num);
#	print_arr(t_digits, 5);	
	print list4;
	print "list3[2:4]", list3[2:6];
	print "Mod val is:", mod_val;
	print "The number is:", ((7*4) +8);
'''
	for x in range(5):
		for x1 in range(5):
			print "matrix1:",matrix1[x][x1];
			print "matrix1:",t_digits[x][x1];
'''


def my_func2():
	num = input('enter the number:');
	list1 = [];
	d_str = str(num);
	list1 = map(int, str(num));
	print list1[1:3];
	print len(list1); 
	print d_str;
	print "printing this number", 2 * int(d_str);
#	print ctypes.c_long(d_str).value;
#	print ''.join(list1);
#	print ctypes.c_long(list.join(list1));


def get_the_subs():
	test_nums = input();

	for x in range(test_nums):
		num = input();
		print "The count is :", get_the_count(str(num));

	return;

def try_subs():
	num = input();
	print "The count is :", get_the_count(str(num));
	return;

def get_the_count(digits):

	t_digits = [['' for x in range(max_digits)] for x in range(max_digits)];
	count = 0L;
	num_len = len(digits); 

	for i in range(num_len):
		for j in range (i):
			t_c = 0;
			t_c = (int(t_digits[j][i-1]) * 10) + int(digits[i]);
			count = (count + (t_c % mod_val)) % mod_val;
			t_digits[j][i] = str(t_c);
		count = (count + int(digits[i]) % mod_val) % mod_val;
		t_digits[i][i] = digits[i];

	#print_arr(t_digits, num_len);
	return count;


def get_raw_input():
	while 1:
		try:
			num = raw_input();
			num_list = num.split(" ");
			print "Hi the input len is", len(num_list);
			#print "list num [0:3]", int(num_list[3]);
		except (EOFError):
			break;


if x < 10:
	print my_printfunc("ok") 
else:
	print my_printfunc("Not ok") 

	#my_func1();
	#my_func2();
	#get_the_subs();
	#try_subs();
	get_raw_input();
