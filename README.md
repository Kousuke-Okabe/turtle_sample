# turtle_sample

## コンパイル
Packegeフォルダ内で実行
> $ catkin build --this

## 実行
### nodeを直接起動
ターミナル１
> $ roscore
> 
ターミナル２
>$ rosrun turtlesim turtlesim_node
>
ターミナル３
> $ rosrus ${パッケージ名} ${ノード名}

### launchファイルを用いて起動
> $ roslaunch ${パッケージ名} ${パッケージ名}.launch

# パッケージ確認順序
1. turtle_publish
3. turtle_subscribe
4. turtle_slient
5. turtle_control

## パッケージ
### パッケージ作成
> $ catkin_create_pkg ${パッケージ名}

### フォルダ構造
* パッケージ名
    * config
        * ${パッケージ名}.yaml
    * launch
        * ${パッケージ名}.launch
    * src
        * ${パッケージ名}.cpp
    * CMakeLists.txt
    * package.xml
