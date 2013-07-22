<?php
/**********************************************************************
*  Author: Chang Xiao (xiaochangfeng@gmail.com)
*  Web...: http://www.chang2chang.com
*  Name..: File Splitter
*  Desc..: A simple file splitter to split csv (or text files)
*  Date..: 6/2/2010
*  PHP Version: 5.x
*/

/*
 * Usage Example
 *
 *
 * // 1. Input and Output files in the current directory
 *
 * $file = new split_file();
 * $result = $file->file_split('randomdata.csv', 'split', 45);
 *
 *
 * // 2. Input file in a directory called source, output files into
 * // data directory
 *
 * $file = new split_file('data');
 * $result = $file->file_split('source/randomdata.csv', 'split', 45);
 * echo $result . ' number of files split';
 *
 */
class split_file {

	/*
	 * @string
	 * Full path or relative path to where the output file will be created
	 */
	private $dest_path;
	
	/*
	 * Constructor
	 */
	public function __construct($dest_path = '') {
		
		if($dest_path == '') {
			$this->log_path = '.';
		} else {
			$this->log_path = $dest_path;
		}
	}
	
	/*
	 ****************************************************************************
	 * Split the input (text) file into smaller files by number of lines
	 * 
	 * @params
	 * (string) source_file		|		File path of the source text file
	 * (string) output_prefix	|		File prefix for the output files
	 * (int) split_count		|		Number of lines per split file
	 *
	 * @returns
	 * (string) file_string		|		The original parsed text file string
	 *									if number of lines was less than the
	 *									split count
	 *
	 * (array) return_files		|		Array containing the file path of 
	 *							|		splitted files.
	 */
	public function file_split($source_file, $output_prefix, $split_count) {
		
		if($file_string = file_get_contents($source_file)) {
			
			// convert line breaks into <br />
			$_file_string = nl2br($file_string);
			$total_line_count = substr_count($_file_string, '<br />');
			
			// if not enough lines to split, we just return the csv string back
			if($total_line_count <= $split_count) {
				return $file_string;
			} else {
				$return_files = array();
				
				// turn the huge file into a 1D array
				$data = explode('<br />', $_file_string);
				// file name append increment counter 
				$x = 0;
				// split increment counter
				$y = 0;
				$buffer = '';
				// walk through the new data array
				for($i = 0; $i< count($data); $i++) {
					$buffer .= $data[$i];
					$y++;
					if($y >= $split_count) {
						$x++;
						$buffer = trim($buffer);
						$this->_write($buffer, $output_prefix . $x . '.csv');
						$return_files[] = $this->log_path . '/' . $output_prefix . $x . '.csv';
						
						// start over
						$y = 0;
						$buffer = '';
						// unset($y, $buffer);
					}
					
					// when we reach the end
					if(count($data) - $i == 1) {
						$x++;
						$buffer = trim($buffer);
						$this->_write($buffer, $output_prefix . $x . '.csv');	
						$return_files[] = $this->log_path . '/' . $output_prefix . $x . '.csv';						
					}
					
				}
				
				return $return_files;
				
			}
		}
	}

	/***************************************************************
	 * Internal function that writes lines into files (appending)
	 *
	 * @params
	 * (string) message		|	content to be written
	 * (string) file_name	|	just the file name of the file to be written
	 *
	 * @returns
	 * TRUE					|	write successful
	 * FALSE				|	write unsuccessful
	 */
	private function _write($message, $file_name) {
		
		if(!is_dir($this->log_path)) {
			mkdir($this->log_path, 777);
		}
		
		$_file_name = $this->log_path . '/' . $file_name;
	
		if($handle = fopen($_file_name, 'a')) {
			$re = fwrite($handle, $message);
			$re2 = fclose($handle);
			if ( $re != false && $re2 != false ) return true;
		}
		return false;		
	}
	
}
?>