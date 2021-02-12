#define debug(x) cout<<#x<<": "<<(x)<<endl;
#define outVe(x) {for(auto i:x){cout<<i<<", ";}cout<<endl;};
class Solution {
public:

    int str_int(string s){
        int ret = 0;
        for(char c:s){
            if( c<'0' || c>'9' ){
                return -1;
            }
            ret *= 10;
            ret += c - '0';
            if(ret > 255){
                return -1;
            }
        }
        return ret;
    }

    bool ip6Num(string str){
        if(str.size()>4){
            return false;
        }

        for(char c:str){
            if( ( c>='0' && c<='9') ||
                ( c>='a' && c<='f') ||
                ( c>='A' && c<='F')
            ){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }

    vector<string> split(string str,string c){
        int pos = -1;
        vector<string> ret;

        bool flag = false;

        if( str[str.size()-1] == c[0] ){
            flag = true;
        }

        while( (pos=str.find(c)) != -1){
            ret.push_back( str.substr(0,pos) );
            str = str.substr(pos + 1);
        }
        if(str.size() > 0 || flag){
            ret.push_back(str);
        }
        return ret;
    }

    string validIPAddress(string IP) {
        //string str = ".172.16.254.1";
        //string c = ".";
        
        if(IP.find(".")!=-1){
            vector<string> ret = split(IP,".");
            if(ret.size() != 4){
                return "Neither";
            }
            for(string& str:ret ){
                if(str.size()==0){
                    return "Neither";
                }
                if(str.size() > 1 && str[0]=='0'){
                    return "Neither";
                }
                int num = str_int(str);
                if(num > 255 || num < 0){
                    return "Neither";
                }
            }
            return "IPv4";

        }else if(IP.find(":")!=-1){
            
            vector<string> ret = split(IP,":");
            //outVe(ret)
            if(ret.size()!=8){
                return "Neither";
            }
            for(string& str:ret ){
                if(str.size()==0){
                    return "Neither";
                }
                if(!ip6Num(str)){
                    return "Neither";
                }
            }
            return "IPv6";

        }else{
            return "Neither";
        }
        return "Neither";
    }
};