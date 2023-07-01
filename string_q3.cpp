/*길이가 최대 100 인 문자열을 입력 받아서 소문자는 대문자로,
 대문자는 소문자로 출력하는 함수를 만들어보세요. (난이도 : 下)
  예를 들어서 "aBcDE" 입력 --> "AbCde" 출력*/
  #include <stdio.h>
  int change_size(char *p);
  int main(){
    char str[100];
    printf("Enter the literal that maximum length is 100. : ");
    scanf("%s", str);
    change_size(str);
    printf("The result of the change_size is : %s", str);

    return 0;
  }

  int change_size(char *p){
    while(*p){
        if(*p >= 65 && *p <= 90){ /*대문자 => 소문자*/
            *p += 32; 
        }else if(*p >= 97 && *p <= 122){ /*소문자 => 대문자*/
            *p -= 32;
        }
        p++;
    }
    return 0;
  }