#include <unistd.h>
#include "command.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

command cmd;

int main() {
	vector<string> terminal_feedback, error_list;
	bool got_network_connection = false;

	while (!got_network_connection) {
		cmd.exec("curl -s google.com", terminal_feedback, error_list);
		if (terminal_feedback.size() > 0) {
			if (terminal_feedback[0][0] == '<') {
				got_network_connection = true; }
			else usleep(1000 * 1000);
		}
		else usleep(1000 * 1000);
	}
	
	string get_time = "sudo date -s \"$(wget -qSO- --max-redirect=0 google.com 2>&1 | grep Date: | cut -d' ' -f5-8)Z\"";
	cmd.exec(get_time.c_str(), terminal_feedback, error_list);
	return 0;
}
