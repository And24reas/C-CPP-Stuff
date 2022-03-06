// to load cvs data from a file. The function return 1, if loading data successed, but 0 if not
int CSVFormater::LoadDataFromeFile(const char *ap_file_path)
{
	FILE *p_file = fopen(ap_file_path, "rb");
	// to check the validation of opening the file
	if (p_file != NULL) {
		// go to the end of the file content to get the size of the file
		fseek(p_file, 0, SEEK_END);
		m_file_size = ftell(p_file);
		// and then again go back to the beginning
		fseek(p_file, 0, SEEK_SET);

		mp_file_data = new char[m_file_size + 1];	// plus 1 to add NULL at the end of string
		fread(mp_file_data, 1, m_file_size, p_file);
		*(mp_file_data + m_file_size) = 0;

		fclose(p_file);
		return 1;	// SUCSSES
	} else return 0;	// FAIL
}