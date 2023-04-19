import sys
import re
from importlib import import_module
import traceback

class color:
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARN = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'

class TestCase:
    def __init__(self, inputs, output):
        self.inputs = inputs
        self.output = output
    def run(self, function_ref):
        try:
            result = function_ref(*self.inputs)
        except Exception as e:
            return False, self.format_error_message(traceback.format_exc())
        if result == self.output:
            return True, self.format_success_message()
        else:
            return False, self.format_error_message(result)
    def format_success_message(self):
        return color.OKGREEN + "Passed. " + color.ENDC + "With inputs %s, returned %s." % (self.inputs, self.output)
    def format_error_message(self, got):
        return color.FAIL + "Failed. " + color.ENDC + "With inputs %s, expected %s, instead got:\n %s" % (self.inputs, self.output, got)

class Exercise:
    def __init__(self, name, module, func_name):
        self.module = module
        self.func_name = func_name
        self.name = name
        self.tests = []
    def add_test(self, test_case):
        self.tests.append(test_case)
    def run_tests(self):
        print("Running tests for %s\n=============" % self.name)
        try:
            func = getattr(self.module, self.func_name)
        except AttributeError:
            print(color.WARN + "Fail: " + color.ENDC + "no function named '%s' exists\n" % self.func_name)
            return
        results = []
        for i in range(len(self.tests)):
            result, message = self.do_test(i, func)
            print(message)
            results.append(result)
        success_rate = sum(results)/len(results)
        if success_rate == 1:
            print("You passed all of the tests!\n")
        else:
            print("You passed %s/%s tests.\n" % (sum(results), len(results)))
    def do_test(self, test_index, function_ref):
        result, message = self.tests[test_index].run(function_ref)
        return result, message

def import_file_or_fail(filename):
    modulename = re.sub(r"\.py$", "", filename)
    try:
        return __import__(modulename, globals(), locals(), ['*'])
    except ImportError:
        print("Error: could not find file %s" % filename)
        exit()

def main():
    try:
        filename = sys.argv[1]
    except IndexError:
        print("Error: please provide a file to be tested.")
        exit()
    testmodule = import_file_or_fail(filename)

    exercise_1 = Exercise("Exercise 1: check_e() function", testmodule, "check_e")
    exercise_1.add_test(TestCase(["hello"], True))
    exercise_1.add_test(TestCase(["CLEMSON"], True))
    exercise_1.add_test(TestCase(["Friday"], False))
    exercise_1.run_tests()

    exercise_2 = Exercise("Exercise 2: check_letter()", testmodule, "check_letter")
    exercise_2.add_test(TestCase(["e","hello"], True))
    exercise_2.add_test(TestCase(["e","HELLO"], True))
    exercise_2.add_test(TestCase(["E","hello"], True))
    exercise_2.add_test(TestCase(["E","HELLO"], True))
    exercise_2.add_test(TestCase(["a","hello"], False))
    exercise_2.add_test(TestCase(["l","clemson"], True))
    exercise_2.add_test(TestCase(["l","CLEMSON"], True))
    exercise_2.add_test(TestCase(["L","clemson"], True))
    exercise_2.add_test(TestCase(["L","CLEMSON"], True))
    exercise_2.add_test(TestCase(["f","clemson"], False))
    exercise_2.run_tests()

    exercise_3 = Exercise("Exercise 3: check_letter_message()", testmodule, "check_letter_message")
    exercise_3.add_test(TestCase(["e","hello"], "The letter e is included in hello"))
    exercise_3.add_test(TestCase(["e","HELLO"], "The letter e is included in HELLO"))
    exercise_3.add_test(TestCase(["E","hello"], "The letter E is included in hello"))
    exercise_3.add_test(TestCase(["E","HELLO"], "The letter E is included in HELLO"))
    exercise_3.add_test(TestCase(["a","hElLo"], "The letter a is not included in hElLo"))
    exercise_3.add_test(TestCase(["l","clemson"], "The letter l is included in clemson"))
    exercise_3.add_test(TestCase(["l","CLEMSON"], "The letter l is included in CLEMSON"))
    exercise_3.add_test(TestCase(["L","clemson"], "The letter L is included in clemson"))
    exercise_3.add_test(TestCase(["L","CLEMSON"], "The letter L is included in CLEMSON"))
    exercise_3.add_test(TestCase(["f","cLeMsOn"], "The letter f is not included in cLeMsOn"))
    exercise_3.run_tests()
    
    exercise_4 = Exercise("Exercise 4: check_letter_count()", testmodule, "check_letter_count")
    exercise_4.add_test(TestCase(["a","banana"], "The letter a is included in banana 3 times"))
    exercise_4.add_test(TestCase(["e","Yeeeaeeeh TIGERS"], "The letter e is included in Yeeeaeeeh TIGERS 7 times"))
    exercise_4.add_test(TestCase(["E","Yeeeaeeeh TIGERS"], "The letter E is included in Yeeeaeeeh TIGERS 7 times"))
    exercise_4.add_test(TestCase(["c","Yeeeaeeeh TIGERS"], "The letter c is not included in Yeeeaeeeh TIGERS"))
    exercise_4.run_tests()

    
if __name__ == "__main__":
    main()
