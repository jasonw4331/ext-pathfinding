--TEST--
Check if pathfinding is loaded
--SKIPIF--
<?php
if (!extension_loaded('pathfinding')) {
    echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "pathfinding" is available';
?>
--EXPECT--
The extension "pathfinding" is available