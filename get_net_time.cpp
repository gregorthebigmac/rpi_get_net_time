#include "command.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

command cmd;

int main() {
	vector<string> terminal_feedback, error_list;
	cmd.exec("curl google.com", terminal_feedback, error_list);
	if (terminal_feedback.size() > 0) {
		if (terminal_feedback[0][0] == '<') {
			cout << "We got a network connection!" << endl; }
	}
	else {
		cout << "No network connection! Dumping contents of [error_list], followed by [terminal_feedback]..." << endl;
		if (error_list.size() > 0) {
			for (int i = 0; i < error_list.size(); i++) {
				cout << error_list[i];
			}
		}
		else cout << endl << endl << "Nothing in [error_list]!" << endl << endl;
		if (terminal_feedback.size() > 0) {
			for (int i = 0; i < terminal_feedback.size(); i++) {
				cout << terminal_feedback[i];
			}
		}
		else cout << endl << endl << "Nothing in [terminal_feedback]!" << endl << endl;
		return 1;
	}
	string get_time = "sudo date -s \"$(wget -qSO- --max-redirect=0 google.com 2>&1 | grep Date: | cut -d' ' -f5-8)Z\"";
	cmd.exec(get_time.c_str(), terminal_feedback, error_list);
	return 0;
}
