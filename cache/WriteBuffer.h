/*WriteBuffers holds writes and when there are enough entries, it flushes them out to storage.
Since during write, the write buffer needs to be blocked and hence no incoming writes can be stored. The solution is to have 2 buffers-
one to accept incoming messages and one to flush them out. When buffer for incoming messages is nearly full, the roles are swapped and 
flush buffer now acts as incoming
*/

class WriteBuffer{

}