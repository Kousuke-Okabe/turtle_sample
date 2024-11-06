# turtle_sample

# コンパイル
Packegeフォルダ内で実行
>$ catkin build --this

# 実行
1. nodeを直接起動
    ターミナル１
    >$ roscore

ターミナル２
    $ rosrun turtlesim turtlesim_node

ターミナル３
    $ rosrus (パッケージ名) (ノード名)

2. launchファイルを用いて起動

    $ roslaunch (パッケージ名) (パッケージ名).launch

# パッケージ確認順序
1. turtle_publish

2. turtle_subscribe

3. turtle_slient

4. turtle_control

# パッケージ
1. パッケージ作成

    $ catkin_create_pkc (パッケージ名)

2. フォルダ構造

    パッケージ
        >config
            >(パッケージ名).yaml
        >launch
            >(パッケージ名).launch
        >src
            >(パッケージ名).cpp
        >CMakeLists.txt
        >package.xml