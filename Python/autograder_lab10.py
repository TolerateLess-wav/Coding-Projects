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

    exercise_1 = Exercise("Exercise 1: add_numbers function", testmodule, "add_numbers")
    exercise_1.add_test(TestCase([[1, 2, 3]], 6))
    exercise_1.add_test(TestCase([[-1, 0, 1]], 0))
    exercise_1.add_test(TestCase([[3.14, 5.2, 7.41]], 15.75))
    exercise_1.run_tests()

    exercise_2 = Exercise("Exercise 2: add_vectors function", testmodule, "add_vectors")
    exercise_2.add_test(TestCase([[1, 2, 3],[4, 5, 6]], [5, 7, 9]))
    exercise_2.add_test(TestCase([[1, 2, 3],[-1, -2, -3]], [0, 0, 0]))
    exercise_2.add_test(TestCase([[3.14, 5.2, 7.41],[4.76, 10.5, 18.52]], [7.90, 15.7, 25.93]))
    exercise_2.add_test(TestCase([[],[]], []))
    exercise_2.add_test(TestCase([[1, 2, 3],[1, 2]], None))
    exercise_2.add_test(TestCase([[1, 2],[1, 2, 3]], None))
    exercise_2.add_test(TestCase([[1, 2],[]], None))
    exercise_2.add_test(TestCase([[1],[]], None))
    exercise_2.run_tests()

    exercise_3 = Exercise("Exercise 3: word_selector function", testmodule, "word_selector")
    exercise_3.add_test(TestCase(["Go Clemson Tigers"], ["Clemson"]))
    exercise_3.add_test(TestCase(["Winter is coming"], ["Winter", "coming"]))
    exercise_3.add_test(TestCase(["aa bb cc dd"], ["aa", "bb", "cc", "dd"]))
    exercise_3.add_test(TestCase(["hello"], ["hello"]))
    exercise_3.run_tests()


if __name__ == "__main__":
    main()
